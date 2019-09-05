program ZAD_E;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   x,y,x1,y1,x2,y2,l1,l2,a,b,c:extended;
begin
   reset(input,'bisector.in');
   rewrite(output,'bisector.out');
   readln(x,y,x1,y1,x2,y2);
   x1:=x1-x;
   y1:=y1-y;
   x2:=x2-x;
   y2:=y2-y;
   l1:=sqrt(x1*x1+y1*y1);
   l2:=sqrt(x2*x2+y2*y2);
   x1:=x1/l1*l2;
   y1:=y1/l1*l2;
   x1:=x1+x2+x;
   y1:=y1+y2+y;
   a:=y-y1;
   b:=x1-x;
   c:=-(a*x+b*y);
   writeln(a,' ',b,' ',c);
end.
