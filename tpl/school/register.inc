<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
<title>用户注册第一步 --- 网店代购注册</title>
<link href="<?=WEB_URL?>css/ddunite.css" rel="stylesheet" />
<script type="text/javascript" src="<?=WEB_URL?>js/j.js"></script>
</head>

<body onload="document.getElementById('user_name').focus();">
<div class="ddunite_wrap">
<!--login-->
  <div class="ddunite_login ddunite_login_register">
    <h1><a href="http://union.dangdang.com">当当网联盟</a></h1>
    <div class="clear"></div>
  </div>
<!--//login-->

<!--process-->
  <div class="ddunite_process">
    <!--当前--><span class="pcs1_crt">1.填写信息</span>
    <!--非当前<span class="pcs1">1.填写信息</span> -->
    <!--当前<span class="pcs2_crt">2.查收激活邮件激活账户</span> -->
    <!--非当前--><span class="pcs2">2.查收激活邮件激活账户</span>
    <!--当前<span class="pcs3_crt">3.注册成功</span>-->
    <!--非当前--><span class="pcs3">3.注册成功</span>
  </div>
<!--//process-->

<!--register-->
  <div class="ddunite_register unite_reg1">
    <form action="<?=WEB_ROOT?>user/user/subregister" method='POST' name="register" id="register">
      <input type="hidden" name="alliance_type" value="<?=$arr['alliance_type'];?>"/>

	<?php if($err_msg) {?>
	  <ul class="clearfix">
	<?php foreach($err_msg as $err) { ?>
		<li class="wrong"><span><?=$err?></span></li>
	<?php } ?>
	  </ul>
	<?php } ?>

    <h2>设置账户信息</h2>
      <ul class="clearfix">
		<li id="user_name_label"><label style="margin-top:5px;">联盟用户名</label><input type="text" name="user_name" id="user_name" style="height:20px;" class="text" value="<?=$arr['user_name']?>"/><i id="user_name_i"></i><span id="user_name_span" style="margin-top:5px;">请输入您的用户名</span></li>
		
		<li id="email_label"><label style="margin-top:5px;">Email地址</label><input type="text" name="email" id="email" style="height:20px;" class="text" value="<?=$arr['email']?>"/><i id="email_i"></i><span id="email_span" style="margin-top:5px;">请输入您的常用邮箱</span></li>
		
		<li id="password_label"><label style="margin-top:5px;">密码输入</label><input type="password" name="password" id="password" style="height:20px;" class="text" /><i id="password_i"></i><span id="password_span" style="margin-top:5px;">密码由6-20个字符组成，建议用英文字母加数字的组合密码</span></li>
        
		<li id="pass_conf_label"><label style="margin-top:5px;">密码确认</label><input type="password" name="pass_conf" id="pass_conf" style="height:20px;" class="text" /><i id="pass_conf_i"></i><span id="pass_conf_span" style="margin-top:5px;">请再次输入您上面输入的密码</span></li>
      </ul>
    
    <h2>填写个人信息</h2>
      <ul class="clearfix">

       <li id="real_name_label"><label style="margin-top:5px;">真实姓名</label><input type="text" name="contact_real_name" id="contact_real_name" style="height:20px;" class="text" value="<?=$arr['contact_real_name']?>" /><i id="contact_real_name_i"></i><span id="contact_real_name_span" style="margin-top:5px;">真实姓名不可更改，请谨慎填写</span></li>
		
		<li id="mobile_phone_label"><label style="margin-top:5px;">手机号码</label><input type="text" name="mobile_phone" id="mobile_phone" style="height:20px;" class="text" value="<?=$arr['mobile_phone']?>"/><i id="mobile_phone_i"></i><span id="mobile_phone_span" style="margin-top:5px;">为了更好地和您沟通有关事宜，请务必填写真实的手机号码</span></li>

		<li id="phone_label"><label style="margin-top:5px;">固定电话</label><ins><input type="text" class="text wid2" name="prefix_phone" id="prefix_phone" style="height:20px;" value="<?=$arr['prefix_phone']?>"/><i>区号</i></ins><i class="other">-</i><ins class="ins2"><input type="text" class="text wid3" name="phone" id="phone" style="height:20px;" value="<?=$arr['phone']?>"/><i>电话号码</i></ins><i id="phone_i"></i><span id="phone_span"  style="margin-top:5px;">例如：010-58793980-178，区号必填分机可以为空</span></li><!--默认情况-->

        <li id="qq_label"><label style="margin-top:5px;">您的QQ</label><input type="text" name="qq" id="qq" style="height:20px;" class="text" value="<?=$arr['qq']?>"/><i id="qq_i"></i><span id="qq_span" style="margin-top:5px;">请输入您的QQ号码(QQ和MSN至少写一种)</span></li>
        

        <li id="msn_label"><label style="margin-top:5px;">您的MSN</label><input type="text" name="msn" id="msn" style="height:20px;" class="text" value="<?=$arr['msn']?>" /><i id="msn_i"></i><span id="msn_span" style="margin-top:5px;">请输入您的MSN号码</span></li>

      </ul>

	  <h2>填写网店代购信息</h2>
	  <div class="cue">
	      <p>我们会将您的联盟账户和您已有的当当账户进行绑定。您只有使用该当当账号进行购买才可获得联盟收益。您的当当账户将没有每日订单数量限制。</p>
	  </div>
	  <ul class="clearfix">

	  <li id="dangdang_user_name_label"><label style="margin-top:5px;">当当网用户名</label><input type="text" name="dangdang_user_name" id="dangdang_user_name" style="height:20px;" class="text" value="<?=$arr['dangdang_user_name']?>" /><i id="dangdang_user_name_i"></i><span id="dangdang_user_name_span" style="margin-top:5px;">请输入您的当当网用户名</span></li>

	  <li id="dangdang_pass_label"><label style="margin-top:5px;">当当网密码</label><input type="password" name="dangdang_pass" id="dangdang_pass" style="height:20px;" class="text" /><i id="dangdang_pass_i"></i><span id="dangdang_pass_span" style="margin-top:5px;">请输入您的当当网密码</span></li>

	  <li id="wangdian_name_label"><label style="margin-top:5px;">网店名称</label><input type="text" name="wangdian_name" id="wangdian_name" style="height:20px;" class="text" value="<?=$arr['wangdian_name']?>"/><i id="wangdian_name_i"></i><span id="wangdian_name_span" style="margin-top:5px;">请输入网店名称</span></li>

	  <li id="wangdian_url_label"><label style="margin-top:5px;">网店URL地址</label><input type="text" name="wangdian_url" id="wangdian_url" style="height:20px;" class="text" value="<?=$arr['wangdian_url']?>"/><i id="wangdian_url_i"></i><span id="wangdian_url_span" style="margin-top:5px;">请输入网店URL地址</span></li>

	  <li id="verify_code_label"><label style="margin-top:5px;">请输入验证码</label><input type="text" name="verify_code" id="verify_code" style="height:20px;" class="text" /><i id="verify_code_i"></i><span id="verify_code_span" style="margin-top:5px;">请输入验证码</span></li>

	  <li><a href="#img_change" class="code"><img id="verify_img" src="<?=WEB_ROOT?>user/verify" alt="验证码" /></a><a id="verify_click" href="#change_one">看不清楚，换一张</a></li>
        <li class="link"><a href="http://static.dangdang.com/union/topic/2085/210358.shtml" target="_blank">当当联盟代购会员服务协议书</a></li>
	  <li class="btn"><a href="#" id="sub_register">同意以上协议并提交注册</a></li>
	  </ul>
    </form>
  </div>
<!--//register-->

</div>

<!--预置页尾区-->
<?php include(TPLDIR . 'lib/foot_new.inc');?>
<script>
$('#verify_click').click(function(){
				var verify_url = '<?=WEB_ROOT?>user/verify/?t='+Math.random();
				//alert(verify_url);
				//$('#verify_img').attr('src', verify_url);
				document.getElementById('verify_img').src =verify_url;
				window.location.href = '#change_one';
				//alert('change');
});

$('#verify_img').click(function(){
				var verify_url = '<?=WEB_ROOT?>user/verify/?t='+Math.random();
				//alert(verify_url);
				//$('#verify_img').attr('src', verify_url);
				document.getElementById('verify_img').src =verify_url;
				//alert('change');
				window.location.href = '#img_change';
});


function userNameCheck(){
	var user_name = $('#user_name').val();
	user_name = $.trim(user_name);

	var len = user_name.length;
	var mark = false;
	var code = 0;
	for(var i=0; i < len; i++){
		code = user_name.charAt(i);
		if(!((code >= 'a' && code <= 'z') || (code >= '0' && code <= '9') || (code == '-') || (code == '_'))) {
			mark = true;
			break;
		}
	}

	if(mark == false && len > 0) {
		code = user_name.charAt(0);
		if(!(code >= 'a' && code <= 'z')) {
			mark = true;
		}
	}

	if(len < 4 || len > 16 || mark == true) {
		$('#user_name_label').attr('class', 'wrong');
		$('#user_name_span').attr('class', 'line2');
		$('#user_name_span').css('margin-top', '5px');
		$('#user_name_span').html('用户名长度为4－16位，仅限小写字母，数字，横线，下划<br/>线，必须以小写字母开头');
		$('#user_name_i').attr('class', 'input_wrong');
		$('#user_name_i').html('错误');
		is_user_check = false;
		return false;
	}

	$.ajax( {
		cache    : false,
		url      : '<?=WEB_ROOT?>user/user/checkUserName',
		type     : 'GET',
		dataType : 'text',
		data     : 'user_name='+user_name,
		success  : function(s){
			if(s == 1) {
				$('#user_name_label').attr('class', '');
				$('#user_name_span').attr('class', '');
				$('#user_name_span').html('');
				$('#user_name_i').attr('class', 'input_right');
				$('#user_name_i').html('正确');
				is_user_check = true;
				//user_name_exsits = 0;
			} else {
				$('#user_name_label').attr('class', 'wrong');
				$('#user_name_span').attr('class', 'line2');
				$('#user_name_span').css('margin-top', '5px');
				$('#user_name_span').html('该用户名已被使用');
				$('#user_name_i').attr('class', 'input_wrong');
				$('#user_name_i').html('错误');
				is_user_check = false;
				return false;
				//user_name_exsits = 1;
			}
		}

	});	
}
function emailCheck(){
	var email = $('#email').val();
	email = $.trim(email);
	var reg = /^([.a-zA-Z0-9_-])+@([a-zA-Z0-9_-])+((\.[a-zA-Z0-9_-]{2,9}){1,2})$/;
	if(!reg.test(email)) {
		$('#email_label').attr('class', 'wrong');
		$('#email_span').attr('class', 'line2');
		$('#email_span').css('margin-top', '5px');
		$('#email_span').html('不是有效的Email地址');
		$('#email_i').attr('class', 'input_wrong');
		$('#email_i').html('错误');
		is_email_check = false;
		return false;
	}

	$.ajax( {
		cache    : false,
		url      : '<?=WEB_ROOT?>user/user/checkEmail',
		type     : 'GET',
		dataType : 'text',
		data     : 'email='+email,
		success  : function(s){
			if(s == 1) {
				$('#email_label').attr('class', '');
				$('#email_span').attr('class', '');
				$('#email_span').html('');
				$('#email_i').attr('class', 'input_right');
				$('#email_i').html('正确');
				is_email_check = true;
				//user_name_exsits = 0;
			} else {
				$('#email_label').attr('class', 'wrong');
				$('#email_span').attr('class', 'line2');
				$('#email_span').css('margin-top', '5px');
				$('#email_span').html('该邮箱已被使用');
				$('#email_i').attr('class', 'input_wrong');
				$('#email_i').html('错误');
				//user_name_exsits = 1;
				is_email_check = false;
				return false;
			}
		}

	});	
}

function dangdangUserCheck(){
	var dangdang_user_name = $('#dangdang_user_name').val();
	var dangdang_pass = $('#dangdang_pass').val();
	dangdang_user_name = $.trim(dangdang_user_name);
	dangdang_pass = $.trim(dangdang_pass);

	$.ajax( {
		cache    : false,
		url      : '<?=WEB_ROOT?>user/user/checkDangdangUser',
		type     : 'GET',
		dataType : 'text',
		data     : 'dangdang_user_name='+dangdang_user_name+'&dangdang_pass='+dangdang_pass,
		success  : function(s){
			if(s == 1) {
			$('#dangdang_user_name_label').attr('class', '');
			$('#dangdang_user_name_span').attr('class', '');
			$('#dangdang_user_name_span').html('');
			$('#dangdang_user_name_i').attr('class', 'input_right');
			$('#dangdang_user_name_i').html('正确');
			is_dangdang_user_check = true;
			//user_name_exsits = 0;
			} 
			if(s == 2) {
			$('#dangdang_user_name_label').attr('class', 'wrong');
			$('#dangdang_user_name_span').attr('class', 'line2');
			$('#dangdang_user_name_span').css('margin-top', '5px');
			$('#dangdang_user_name_span').html('您的当当网用户名与密码不匹配，请确认后重新填写');
			$('#dangdang_user_name_i').attr('class', 'input_wrong');
			$('#dangdang_user_name_i').html('错误');
			//user_name_exsits = 1;
			is_dangdang_user_check = false;
			return false;
			}
			if(s == 3) {
			$('#dangdang_user_name_label').attr('class', 'wrong');
			$('#dangdang_user_name_span').attr('class', 'line2');
			$('#dangdang_user_name_span').css('margin-top', '5px');
			$('#dangdang_user_name_span').html('您已经输错了5次当当网密码，请30分钟后再输入');
			$('#dangdang_user_name_i').attr('class', 'input_wrong');
			$('#dangdang_user_name_i').html('错误');
			//user_name_exsits = 1;
			is_dangdang_user_check = false;
			return false;
			}
			if(s == 4) {
			$('#dangdang_user_name_label').attr('class', 'wrong');
			$('#dangdang_user_name_span').attr('class', 'line2');
			$('#dangdang_user_name_span').css('margin-top', '5px');
			$('#dangdang_user_name_span').html('该当当网用户名已被绑定至其它联盟账号，请更换');
			$('#dangdang_user_name_i').attr('class', 'input_wrong');
			$('#dangdang_user_name_i').html('错误');
			//user_name_exsits = 1;
			is_dangdang_user_check = false;
			return false;
			}
		}

	});	
}
</script>
<script type="text/javascript" src="<?=WEB_URL?>js/register_valid.js"></script>


</body>
</html>
