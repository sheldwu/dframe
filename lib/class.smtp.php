<?php
class smtp_mail{
    private $bfconfig;
      
    private $mail;

    private $header;
    public function __construct(){
        $this->bfconfig = array (
            'sitename' => '监控邮件',
        );
        $this->mail = array (
            'state' => 1,
            'server' => 'smtp.163.com',
            'port' => 25,
            'auth' => 1,
            'username' => 'wuxudong23@163.com',
            'password' => '82469591',
            'charset' => 'utf8',
            'mailfrom' => 'wuxudong23@163.com'
        );
    }

    private function get_header(){
        $headers = "";
        $headers .= "MIME-Version:1.0\r\n";
        $headers .= "Content-type:text/html\r\n";
        $headers .= "Content-Transfer-Encoding: base64\r\n";
        $headers .= "From: ".$this->bfconfig['sitename']."<".$this->mail['mailfrom'].">\r\n";
        $headers .= "Date: ".date("r")."\r\n";
        list($msec, $sec) = explode(" ", microtime());
        $headers .= "Message-ID: <".date("YmdHis", $sec).".".($msec * 1000000).".".$this->mail['mailfrom'].">\r\n";
        $this->header = $headers;
    }
      
    public function sendmail($mail_to, $mail_subject, $mail_message) {
        $this->get_header();
        date_default_timezone_set('PRC');
        $mail_subject = '=?'.$this->mail['charset'].'?B?'.base64_encode($mail_subject).'?=';
        $mail_message = chunk_split(base64_encode(preg_replace("/(^|(\r\n))(\.)/", "\1.\3",$mail_message)));
        if(!$fp = fsockopen($this->mail['server'], $this->mail['port'], $errno, $errstr, 30)) {
            exit("CONNECT - Unable to connect to the SMTP server");
        }
        stream_set_blocking($fp, 1);
        $lastmessage = fgets($fp, 512);
        if(substr($lastmessage, 0, 3) != '220') {
            exit("CONNECT - ".$lastmessage);
        }
        fputs($fp, ($this->mail['auth'] ? 'EHLO' : 'HELO')." befen\r\n");
        $lastmessage = fgets($fp, 512);
        if(substr($lastmessage, 0, 3) != 220 && substr($lastmessage, 0, 3) != 250) {
            exit("HELO/EHLO - ".$lastmessage);
        }
        while(1) {
            if(substr($lastmessage, 3, 1) != '-' || empty($lastmessage)) {
                break;
            }
            $lastmessage = fgets($fp, 512);
        }
        if($this->mail['auth']) {
            fputs($fp, "AUTH LOGIN\r\n");
            $lastmessage = fgets($fp, 512);
            if(substr($lastmessage, 0, 3) != 334) {
                exit($lastmessage);
            }
            fputs($fp, base64_encode($this->mail['username'])."\r\n");
            $lastmessage = fgets($fp, 512);
            if(substr($lastmessage, 0, 3) != 334) {
                exit("AUTH LOGIN - ".$lastmessage);
            }
            fputs($fp, base64_encode($this->mail['password'])."\r\n");
            $lastmessage = fgets($fp, 512);
            if(substr($lastmessage, 0, 3) != 235) {
                exit("AUTH LOGIN - ".$lastmessage);
            }
            $email_from = $this->mail['mailfrom'];
        }
        fputs($fp, "MAIL FROM: <".preg_replace("/.*\<(.+?)\>.*/", "\\1", $email_from).">\r\n");
        $lastmessage = fgets($fp, 512);
        if(substr($lastmessage, 0, 3) != 250) {
            fputs($fp, "MAIL FROM: <".preg_replace("/.*\<(.+?)\>.*/", "\\1", $email_from).">\r\n");
            $lastmessage = fgets($fp, 512);
            if(substr($lastmessage, 0, 3) != 250) {
                exit("MAIL FROM - ".$lastmessage);
            }
        }
        foreach(explode(',', $mail_to) as $touser) {
            $touser = trim($touser);
            if($touser) {
                fputs($fp, "RCPT TO: <".preg_replace("/.*\<(.+?)\>.*/", "\\1", $touser).">\r\n");
                $lastmessage = fgets($fp, 512);
                if(substr($lastmessage, 0, 3) != 250) {
                    fputs($fp, "RCPT TO: <".preg_replace("/.*\<(.+?)\>.*/", "\\1",$touser).">\r\n");
                    $lastmessage = fgets($fp, 512);
                    exit("RCPT TO - ".$lastmessage);
                }
            }
        }
        fputs($fp, "DATA\r\n");
        $lastmessage = fgets($fp, 512);
        if(substr($lastmessage, 0, 3) != 354) {
            exit("DATA - ".$lastmessage);
        }
        fputs($fp, $this->header);
        fputs($fp, "To: ".$mail_to."\r\n");
        fputs($fp, "Subject: $mail_subject\r\n");
        fputs($fp, "\r\n\r\n");
        fputs($fp, "$mail_message\r\n.\r\n");
        $lastmessage = fgets($fp, 512);
        if(substr($lastmessage, 0, 3) != 250) {
            exit("END - ".$lastmessage);
        }
        fputs($fp, "QUIT\r\n");
    }
}
