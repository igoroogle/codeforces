program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a:array [0..11,0..11] of int64;
   i,j,n:integer;
begin
   read(n);
   for i:=0 to 11 do
      for j:=0 to 11 do a[i,j]:=0;
   for i:=1 to n do a[1,i]:=1;
   for i:=2 to n do
      for j:=1 to n do a[i,j]:=a[i-1,j]+a[i,j-1];
   writeln(a[n,n]);
   readln;
   readln;
end.
