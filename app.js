
  var a;
  var b;
  var op;
  function add(t)
  {
    op=t;
    var n1 = document.getElementById('n1').value;
    a = parseInt(n1); //if i give string value then return NAN
    document.getElementById('n1').value="";
  }

  function sub(t)
  {
    op=t;
    var n1 = document.getElementById('n1').value;
    a = parseInt(n1);
    document.getElementById('n1').value="";
  }

  function mul(t)
  {
    op=t;
    var n1 = document.getElementById('n1').value;
    a = parseInt(n1);
    document.getElementById('n1').value="";
  }

  function div(t)
  {
    op=t;
    var n1 = document.getElementById('n1').value;
    a = parseInt(n1);
    document.getElementById('n1').value="";
  }

  function percent(t)
  {
    op=t;
    var n1 = document.getElementById('n1').value;
    a = parseInt(n1);
    document.getElementById('n1').value="";
  }

  function square(t)
  {
    op=t;
    var n1 = document.getElementById('n1').value;
    a = parseInt(n1);
    document.getElementById('n1').value=a*a;
  }

  function cube(t)
  {
    op=t;
    var n1 = document.getElementById('n1').value;
    a = parseInt(n1);
    document.getElementById('n1').value=a*a*a;
  }

  function squareRoot(t)
  {
    op=t;
    var n1 = document.getElementById('n1').value;
    a = parseInt(n1);
    document.getElementById('n1').value=Math.sqrt(a);
  }

  function fact(t)
  {
    op=t;
    var n1 = document.getElementById('n1').value;
    a = parseInt(n1);
    var f=1;
    for(var i=1;i<=a;i++)
    {
      f=f*i;
    }
    document.getElementById('n1').value=f;
  }

  function log1(t)
  {
    op=t;
    var n1 = document.getElementById('n1').value;
    a = parseInt(n1);
    document.getElementById('n1').value=Math.log(a);
  }

  function exp1(t)
  {
    op=t;
    var n1 = document.getElementById('n1').value;
    a = parseInt(n1);
    document.getElementById('n1').value=Math.exp(a);
  }

  function pow1(t)
  {
    op=t;
    var n1 = document.getElementById('n1').value;
    a = parseInt(n1);
    document.getElementById('n1').value="";
  }



  function one(n) {
    var s = document.getElementById('n1').value;
    if(s=="")
    {
      document.getElementById('n1').value=n;
    }
    else
    {
      s=parseInt(s);
      s=s*10+n;
      document.getElementById('n1').value=s;
    }
    
  }



  function result()
  {
    var n1 = document.getElementById('n1').value;
    b = parseInt(n1);
    switch(op)
    {
      case '+':
      document.getElementById('n1').value=a+b;
      break;

      case '-':
      document.getElementById('n1').value=a-b;
      break;

      case '*':
      document.getElementById('n1').value=a*b;
      break;

      case '/':
      document.getElementById('n1').value=a/b;
      break;

      case 'p':
      document.getElementById('n1').value=a*(b/100);
      break;

      case 'pow1':
      document.getElementById('n1').value=Math.pow(a,b);
      break;

    }
  }

  function clear1(t)
  {
    a=parseInt(t);
    document.getElementById('n1').value=a;
    a="";
    b="";
    op="";
  }