program ZAD_N;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   x,y,a,b,c:int64;
begin
   reset(input,'line2.in');
   rewrite(output,'line2.out');
   readln(x,y,a,b);
   c:=-trunc(1.0*a*x+1.0*b*y);
   writeln(a,' ',b,' ',c);
end.
