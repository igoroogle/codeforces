program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   n1,n2,k1,k2:integer;
begin
   readln(n1,n2,k1,k2);
   if (n1>n2) then writeln('First')
   else writeln('Second');
   readln;
end.
