program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils,Math;
var
   x,y:int64;
begin
   readln(x,y);
   if (arctan2(y,x)<0) then writeln(arctan2(y,x)+2*pi)
   else writeln(arctan2(y,x));
   readln;
end.
