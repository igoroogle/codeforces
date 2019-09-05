program ZAD_B;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   i,j,n,m,x,k:integer;
   a:array [1..1000100] of integer;
begin
   readln(n);
   k:=0;
   for i:=1 to n do
      begin
         read(x);
         x:=k+x;
         for j:=k+1 to x do a[j]:=i;
         k:=x;
      end;
   readln(m);
   for i:=1 to m do
      begin
         read(x);
         writeln(a[x]);
      end;
   readln;
   readln;
end.
