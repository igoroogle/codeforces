program ZAD_C_2;

{$APPTYPE CONSOLE}

uses
  SysUtils,Math;
var
   i,n,m:integer;
   s:real;
begin
   readln(m,n);
   s:=0;
   for i:=1 to m do s:=s+i*(power(i/m,n)-power((i-1)/m,n));
   writeln(s);
   readln;
end.
