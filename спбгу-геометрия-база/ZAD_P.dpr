program ZAD_P;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   x,y,a,b,c:int64;
function ppram(x,y,a,b,c:int64):boolean;
begin
   ppram:=trunc(1.0*a*x+1.0*b*y)+c=0;
end;
begin
   reset(input,'point1.in');
   rewrite(output,'point1.out');
   readln(x,y,a,b,c);
   if (ppram(x,y,a,b,c)) then writeln('YES')
   else writeln('NO');
   readln;
end.
