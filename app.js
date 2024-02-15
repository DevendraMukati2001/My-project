var c=1;
var i=1;
$(document).ready(function(){
    $("#btnAdd").click(function(){
        $("#question-heading"+c).text(c+". "+$("#Q1").val());
        $("#option"+c+"-1").text(i+". "+$("#O1").val());
        i++;
        $("#option"+c+"-2").text(i+". "+$("#O2").val());
        i++;
        $("#option"+c+"-3").text(i+". "+$("#O3").val());
        i++;
        $("#option"+c+"-4").text(i+". "+$("#O4").val());
        c++;
        i=1;
        $("#Q1").val("");
        $("#O1").val("");
        $("#O2").val("");
        $("#O3").val("");
        $("#O4").val("");
    });

    $("#btnSub").click(function(){
        $("#ins-name").text($("#institute-Name").val());
        $("#ins-sub").text($("#Sub").val());
        $("#ins-time").text($("#Time").val());
        $("#testBlock").css({'display':'block'});
        $("#details").css({'display':'none'});
    });

    $("#subTest").click(function(){
        $("#testBlock").css({'display':'none'});
    });
});