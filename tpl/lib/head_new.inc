<?php $menu = Core::config('core.menu_index');?>
<div class="ddunite_wrap">
<!--login-->
  <div class="ddunite_login">
    <h1><a href="<?=WEB_ROOT?>admin/index">当当网联盟</a></h1>
                                                                                                                                                                                                                                                                                                                  <p><span class="username">您好！<a href="<?=WEB_ROOT?>admin/index"><?php echo $this->user->name();?>&nbsp;(<?php echo $this->user->id_str();?>)</a></span><!--<span class="nousername">您好！<a href="#">Tom_2010(P-12345)</a></span> --><?php if($this->user->getUnReadCount() > 0) {?><a href="<?=WEB_ROOT?>msg/recvmsg/" class="mail">站内信(<?php echo $this->user->getUnReadCount();?>)</a><?php } else { ?><a href="<?=WEB_ROOT?>msg/recvmsg/" class="nomail">站内信</a> <?php } ?><!--<a href="#" class="nomail">站内信(4)</a> --><a href="http://static.dangdang.com/union/contents/2085/11515.shtml" target="_blank" class="help">帮助</a><a href="<?=WEB_ROOT?>user/user/exitlogin" class="exit">退出</a></p>
    <div class="clear"></div>
  </div>
<!--//login-->

<!--nav-->
  <div class="ddunite_nav">
    <ul class="clearfix">
        <li <?php if(in_array(Router::$controller,$menu['index'])){ echo 'class="index current"';} else { echo 'class="index"';} ?>  ><a href="<?=WEB_ROOT?>admin/index">首页</a></li>
        <li <?php if(in_array(Router::$controller,$menu['ads'])){ echo 'class="current"';} ?>><a href="<?=WEB_ROOT?>ads/prodads">广告制作</a></li><!--当前状态添加current样式-->
		<?php
			$balance_expect_switch = Core::config("core.balance_expect_switch");
		?>
      <li <?php if(in_array(Router::$controller,$menu['report'])){ echo 'class="current"';} ?>><a href="<?=WEB_ROOT?>admin/<?php if($balance_expect_switch === TRUE){echo 'expect';}else{echo 'trace';}?>">统计报表</a></li>
      <li <?php if(in_array(Router::$controller,$menu['msg'])){ echo 'class="current"';} ?>><a href="<?=WEB_ROOT?>msg/recvmsg/showindex">消息中心</a></li>
      <li <?php if(in_array(Router::$method,$menu['account'])){ echo 'class="current"';} ?>><a href="<?=WEB_ROOT?>user/account/chagaccount">账户管理</a></li>
	<?php if ($this->user->type()==5&&$this->user->getVerifyStatus()>=2){?>
	<li <?php if(in_array(Router::$method,$menu['school'])){ echo 'class="school current"';}else{echo 'class="school"';} ?>><a href="<?=WEB_ROOT?>agent/school/school_index">校园代理专区</a></li><?}?>
	<?php if ($this->user->type()==6&&$this->user->getVerifyStatus()>=2){?>
	<li <?php if(in_array(Router::$method,$menu['eshop'])){ echo 'class="school current"';}else{echo 'class="school"';} ?>><a href="<?=WEB_ROOT?>agent/eshop/eshop_index">网店代购专区</a></li><?}?>
    </ul>
  </div>
  <div <?php if(in_array(Router::$controller,$menu['ads'])){ echo 'class="ddunite_subnav sub1"';}else { echo 'style="display:none;"';} ?>>
    <ul class="clearfix">
      <li <?php if(Router::$controller == $menu['ads']['makeproduct']) { echo ' class="subcurrent"';}?>><a href="<?=WEB_ROOT?>ads/prodads">推广商品</a></li>
      <li <?php if(Router::$controller == $menu['ads']['makesubject']) { echo ' class="subcurrent"';}?>><a href="<?=WEB_ROOT?>ads/makesubjectad">推广主题</a></li>
      <li <?php if(Router::$controller == $menu['ads']['makesearch']) { echo ' class="subcurrent"';}?>><a href="<?=WEB_ROOT?>ads/makesearchad" >推广搜索</a></li>
      <li <?php if(Router::$controller == $menu['ads']['maketext']) { echo ' class="subcurrent"';}?> ><a href="<?=WEB_ROOT?>ads/maketextad">自定义链接</a></li><!--当前状态添加subcurrent样式-->
      <li <?php if(Router::$controller == $menu['ads']['makesmartad']) { echo ' class="subcurrent"';}?> ><a href="<?=WEB_ROOT?>ads/makesmartad">智能广告</a></li>
	 <!-- <li><a href="#">智能广告</a></li>-->
      <li <?php if(Router::$controller == $menu['ads']['toolbar']) { echo ' class="subcurrent"';}?> ><a href="<?=WEB_ROOT?>ads/toolbar">工具条广告</a></li>
    </ul>
  </div>

  <div <?php if(in_array(Router::$method,$menu['account'])){ echo 'class="ddunite_subnav sub4"';}else { echo 'style="display:none;"';} ?>>
    <ul class="clearfix">
      <li <?php if(Router::$method == $menu['account']['chagaccount'] || Router::$method == $menu['account']['subchagaccount']) { echo ' class="subcurrent"';}?>><a href="<?=WEB_ROOT?>user/account/chagaccount">账户信息</a></li>
      <li <?php if(Router::$method == $menu['account']['chagpayinfo'] || Router::$method == $menu['account']['subchagpayinfo']) { echo ' class="subcurrent"';}?>><a href="<?=WEB_ROOT?>user/account/chagpayinfo">网站和结算管理</a></li>
      <li <?php if(Router::$method == $menu['account']['chagpass'] || Router::$method == $menu['account']['subpass']) { echo ' class="subcurrent"';}?>><a href="<?=WEB_ROOT?>user/account/chagpass">密码修改</a></li><!--当前状态添加current样式-->
    </ul>
  </div>

	<div <?php if(in_array(Router::$controller,$menu['msg'])){ echo 'class="ddunite_subnav sub3"';}else { echo 'style="display:none;"';} ?>>
    <ul class="clearfix">
      <li<?php if(Router::$controller == $menu['msg']['notice'] ) { echo ' class="subcurrent"';}?>><a href="<?=WEB_ROOT?>msg/notice">联盟公告</a></li>
      <li<?php if(Router::$controller == $menu['msg']['sendmsg'] || Router::$controller == $menu['msg']['recvmsg']) { echo ' class="subcurrent"';}?>><a href="<?=WEB_ROOT?>msg/recvmsg">站内信</a></li><!--当前状态添加current样式-->
      <li <?php if(Router::$controller == $menu['msg']['suggest'] ) { echo ' class="subcurrent"';}?>><a href="<?=WEB_ROOT?>msg/suggest">意见反馈</a></li>
    </ul>
  </div>

  <div <?php if(in_array(Router::$controller,$menu['report'])){ echo 'class="ddunite_subnav sub2"';}else { echo 'style="display:none;"';} ?>>
    <ul class="clearfix">
      <li<?php if(Router::$controller == $menu['report']['trace'] ) { echo ' class="subcurrent"';}?>><a href="<?=WEB_ROOT?>admin/trace" >订单跟踪</a></li><!----><!--当前状态添加current样式-->
      <<?php if($balance_expect_switch === FALSE){echo "!--";}?>li<?php if(Router::$controller == $menu['report']['expect'] ) { echo ' class="subcurrent"';}?>><a href="<?=WEB_ROOT?>admin/expect">收益报表</a></li<?php if($balance_expect_switch === FALSE){echo "--";}?>>
      <!--<li><a href="#">广告效果</a></li>-->
      <li<?php if(Router::$controller == $menu['report']['comm'] ) { echo ' class="subcurrent"';}?>><a href="<?=WEB_ROOT?>admin/comm">佣金结算历史</a></li>
    </ul>
  </div>
<!--//nav-->
