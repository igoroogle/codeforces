program ZAD_F_2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a,b,c,i:integer;
   s:extended;
begin
   readln(a,b,c);
   s:=0;
   for i:=a to b do s:=s+i/(b-a+1);
   if (c>=s) then writeln('Stay with this envelope')
   else writeln('Take another envelope');
   readln;
end.
