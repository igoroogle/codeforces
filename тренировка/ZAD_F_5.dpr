program ZAD_F_5;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a,b,c,i,t1,t2:integer;
   m,t:extended;
begin
   readln(a,b,c);
   m:=0;
   for 
   if (m>=c) then writeln('Take another envelope')
   else writeln('Stay with this envelope');
   readln;
end.
