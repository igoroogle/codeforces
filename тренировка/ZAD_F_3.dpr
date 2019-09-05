program ZAD_F_3;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a,b,c:int64;
begin
   readln(a,b,c);
   if (c>=b) or (c) then writeln('Stay with this envelope')
   else writeln('Take another envelope');
   readln;
end.
