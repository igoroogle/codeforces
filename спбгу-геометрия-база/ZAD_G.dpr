program ZAD_G;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   x,y,x1,y1,x2,y2,a,b,c:extended;
begin
   reset(input,'distance2.in');
   rewrite(output,'distance2.out');
   readln(x,y,x1,y1,x2,y2);
   a:=y1-y2;
   b:=x2-x1;
   c:=-(a*x1+b*y1);
   writeln(abs(a*x+b*y+c)/sqrt(a*a+b*b));
end.
