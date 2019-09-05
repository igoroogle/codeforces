program ZAD_F;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   x,y,a,b,c:extended;
begin
   reset(input,'distance1.in');
   rewrite(output,'distance1.out');
   readln(x,y,a,b,c);
   writeln(abs(a*x+b*y+c)/sqrt(a*a+b*b));
end.
