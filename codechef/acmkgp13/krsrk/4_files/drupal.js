var Drupal=Drupal||{settings:{},behaviors:{},themes:{},locale:{}};Drupal.jsEnabled=true;Drupal.attachBehaviors=function(a){a=a||document;jQuery.each(Drupal.behaviors,function(){this(a)})};Drupal.checkPlain=function(d){d=String(d);var a={"&":"&amp;",'"':"&quot;","<":"&lt;",">":"&gt;"};for(var c in a){var b=new RegExp(c,"g");d=d.replace(b,a[c])}return d};Drupal.t=function(c,a){if(Drupal.locale.strings&&Drupal.locale.strings[c]){c=Drupal.locale.strings[c]}if(a){for(var b in a){switch(b.charAt(0)){case"@":a[b]=Drupal.checkPlain(a[b]);break;case"!":break;case"%":default:a[b]=Drupal.theme("placeholder",a[b]);break}c=c.replace(b,a[b])}}return c};Drupal.formatPlural=function(e,d,c,b){var b=b||{};b["@count"]=e;var a=Drupal.locale.pluralFormula?Drupal.locale.pluralFormula(b["@count"]):((b["@count"]==1)?0:1);if(a==0){return Drupal.t(d,b)}else{if(a==1){return Drupal.t(c,b)}else{b["@count["+a+"]"]=b["@count"];delete b["@count"];return Drupal.t(c.replace("@count","@count["+a+"]"))}}};Drupal.theme=function(c){for(var b=1,a=[];b<arguments.length;b++){a.push(arguments[b])}return(Drupal.theme[c]||Drupal.theme.prototype[c]).apply(this,a)};Drupal.parseJson=function(data){if((data.substring(0,1)!="{")&&(data.substring(0,1)!="[")){return{status:0,data:data.length?data:Drupal.t("Unspecified error")}}return eval("("+data+");")};Drupal.freezeHeight=function(){Drupal.unfreezeHeight();var a=document.createElement("div");$(a).css({position:"absolute",top:"0px",left:"0px",width:"1px",height:$("body").css("height")}).attr("id","freeze-height");$("body").append(a)};Drupal.unfreezeHeight=function(){$("#freeze-height").remove()};Drupal.encodeURIComponent=function(b,a){a=a||location.href;b=encodeURIComponent(b).replace(/%2F/g,"/");return(a.indexOf("?q=")!=-1)?b:b.replace(/%26/g,"%2526").replace(/%23/g,"%2523").replace(/\/\//g,"/%252F")};Drupal.getSelection=function(d){if(typeof(d.selectionStart)!="number"&&document.selection){var c=document.selection.createRange();var a=c.duplicate();a.moveToElementText(d);a.setEndPoint("EndToEnd",c);var e=a.text.length-c.text.length;var b=e+c.text.length;return{start:e,end:b}}return{start:d.selectionStart,end:d.selectionEnd}};Drupal.ahahError=function(a,c){if(a.status==200){if(jQuery.trim(a.responseText)){var b=Drupal.t("An error occurred. \n@uri\n@text",{"@uri":c,"@text":a.responseText})}else{var b=Drupal.t("An error occurred. \n@uri\n(no information available).",{"@uri":c})}}else{var b=Drupal.t("An HTTP error @status occurred. \n@uri",{"@uri":c,"@status":a.status})}return b.replace(/\n/g,"<br />")};$(document.documentElement).addClass("js");$(document).ready(function(){Drupal.attachBehaviors(this)});Drupal.theme.prototype={placeholder:function(a){return"<em>"+Drupal.checkPlain(a)+"</em>"}};