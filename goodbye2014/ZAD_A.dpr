program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a:array [1..30010] of integer;
   i,j,n,t:integer;
begin
   read(n,t);
   for i:=1 to n-1 do read(a[i]);
   j:=1;
   while j<t do j:=j+a[j];
   if (j=t) then writeln('YES')
   else writeln('NO');
   readln;
   readln;
end.
