program ZAD_M;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   x1,y1,x2,y2,a,b,c:int64;
begin
   reset(input,'line1.in');
   rewrite(output,'line1.out');
   readln(x1,y1,x2,y2);
   a:=y1-y2;
   b:=x2-x1;
   c:=-trunc(1.0*a*x1+1.0*b*y1);
   writeln(a,' ',b,' ',c);
end.
