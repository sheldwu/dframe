<?php $menu = Core::config('core.menu_index');?>
<div class="ddunite_wrap">
<!--login-->
  <div class="ddunite_login">
    <h1><a href="#">����������</a></h1>
                                                                                                                                                                                                                                                                                                                  <p><span class="username">���ã�<a href="<?=WEB_ROOT?>admin/index"><?php echo $this->user->name();?>&nbsp;(<?php echo $this->user->id_str();?>)</a></span><!--<span class="nousername">���ã�<a href="#">Tom_2010(P-12345)</a></span> --><a href="<?=WEB_ROOT?>msg/recvmsg/" class="mail">վ����(<?php echo $this->user->getUnReadCount();?>)</a><!--<a href="#" class="nomail">վ����(4)</a> --><a href="http://static.dangdang.com/union/contents/2085/11515.shtml" target="_blank" class="help">����</a><a href="<?=WEB_ROOT?>user/user/exitlogin" class="exit">�˳�</a></p>
    <div class="clear"></div>
  </div>
<!--//login-->

<!--nav-->
  <div class="ddunite_nav">
    <ul class="clearfix">
        <li <?php if(in_array(Router::$controller,$menu['index'])){ echo 'class="index current"';} else { echo 'class="index"';} ?>  ><a href="<?=WEB_ROOT?>admin/index">��ҳ</a></li>
        <li <?php if(in_array(Router::$controller,$menu['ads'])){ echo 'class="current"';} ?>><a href="<?=WEB_ROOT?>ads/prodads">�������</a></li><!--��ǰ״̬����current��ʽ-->
      <li <?php if(in_array(Router::$controller,$menu['report'])){ echo 'class="current"';} ?>><a href="<?=WEB_ROOT?>admin/expect">ͳ�Ʊ���</a></li>
      <li <?php if(in_array(Router::$controller,$menu['msg'])){ echo 'class="current"';} ?>><a href="<?=WEB_ROOT?>msg/recvmsg/showindex">��Ϣ����</a></li>
      <li <?php if(in_array(Router::$method,$menu['account'])){ echo 'class="current"';} ?>><a href="<?=WEB_ROOT?>user/account/chagaccount">�˻�����</a></li>
    </ul>
  </div>
  <div <?php if(in_array(Router::$controller,$menu['ads'])){ echo 'class="ddunite_subnav sub1"';}else { echo 'style="display:none;"';} ?>>
    <ul class="clearfix">
      <li <?php if(Router::$controller == $menu['ads']['makeproduct']) { echo ' class="subcurrent"';}?>><a href="<?=WEB_ROOT?>ads/prodads">�ƹ���Ʒ</a></li>
      <li <?php if(Router::$controller == $menu['ads']['makesubject']) { echo ' class="subcurrent"';}?>><a href="<?=WEB_ROOT?>ads/makesubjectad">�ƹ�����</a></li>
      <li <?php if(Router::$controller == $menu['ads']['makesearch']) { echo ' class="subcurrent"';}?>><a href="<?=WEB_ROOT?>ads/makesearchad" >�ƹ�����</a></li>
      <li <?php if(Router::$controller == $menu['ads']['maketext']) { echo ' class="subcurrent"';}?> ><a href="<?=WEB_ROOT?>ads/maketextad">�Զ�������</a></li><!--��ǰ״̬����subcurrent��ʽ-->
      <li <?php if(Router::$controller == $menu['ads']['makesmartad']) { echo ' class="subcurrent"';}?> ><a href="<?=WEB_ROOT?>ads/makesmartad">���ܹ��</a></li>
	 <!-- <li><a href="#">���ܹ��</a></li>-->
    </ul>
  </div>

  <div <?php if(in_array(Router::$method,$menu['account'])){ echo 'class="ddunite_subnav sub4"';}else { echo 'style="display:none;"';} ?>>
    <ul class="clearfix">
      <li <?php if(Router::$method == $menu['account']['chagaccount'] || Router::$method == $menu['account']['subchagaccount']) { echo ' class="subcurrent"';}?>><a href="<?=WEB_ROOT?>user/account/chagaccount">�˻���Ϣ</a></li>
      <li <?php if(Router::$method == $menu['account']['chagpayinfo'] || Router::$method == $menu['account']['subchagpayinfo']) { echo ' class="subcurrent"';}?>><a href="<?=WEB_ROOT?>user/account/chagpayinfo">��վ�ͽ������</a></li>
      <li <?php if(Router::$method == $menu['account']['chagpass'] || Router::$method == $menu['account']['subpass']) { echo ' class="subcurrent"';}?>><a href="<?=WEB_ROOT?>user/account/chagpass">�����޸�</a></li><!--��ǰ״̬����current��ʽ-->
    </ul>
  </div>

	<div <?php if(in_array(Router::$controller,$menu['msg'])){ echo 'class="ddunite_subnav sub3"';}else { echo 'style="display:none;"';} ?>>
    <ul class="clearfix">
      <li<?php if(Router::$controller == $menu['msg']['notice'] ) { echo ' class="subcurrent"';}?>><a href="<?=WEB_ROOT?>msg/notice">���˹���</a></li>
      <li<?php if(Router::$controller == $menu['msg']['sendmsg'] || Router::$controller == $menu['msg']['recvmsg']) { echo ' class="subcurrent"';}?>><a href="<?=WEB_ROOT?>msg/recvmsg">վ����</a></li><!--��ǰ״̬����current��ʽ-->
      <li <?php if(Router::$controller == $menu['msg']['suggest'] ) { echo ' class="subcurrent"';}?>><a href="<?=WEB_ROOT?>msg/suggest">�������</a></li>
    </ul>
  </div>

  <div <?php if(in_array(Router::$controller,$menu['report'])){ echo 'class="ddunite_subnav sub2"';}else { echo 'style="display:none;"';} ?>>
    <ul class="clearfix">
      <li<?php if(Router::$controller == $menu['report']['trace'] ) { echo ' class="subcurrent"';}?>><a href="<?=WEB_ROOT?>admin/trace" >��������</a></li><!----><!--��ǰ״̬����current��ʽ-->
      <li<?php if(Router::$controller == $menu['report']['expect'] ) { echo ' class="subcurrent"';}?>><a href="<?=WEB_ROOT?>admin/expect">���汨��</a></li>
      <!--<li><a href="#">���Ч��</a></li>-->
      <li<?php if(Router::$controller == $menu['report']['comm'] ) { echo ' class="subcurrent"';}?>><a href="<?=WEB_ROOT?>admin/comm">Ӷ�������ʷ</a></li>
    </ul>
  </div>
<!--//nav-->