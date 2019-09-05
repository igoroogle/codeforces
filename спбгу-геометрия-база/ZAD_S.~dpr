program ZAD_S;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   x1,y1,x2,y2,a,b,c:int64;
begin
   reset(input,'position.in');
   rewrite(output,'position.out');
   readln(x1,y1,x2,y2,a,b,c);
   if (trunc((1.0*a*x1+1.0*b*y1+c)*(1.0*a*x2+1.0*b*y2+c))>0) then writeln('YES')
   else writeln('NO');
   readln;
end.
