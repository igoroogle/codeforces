program ZAD_B;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a,b:array [1..4096] of integer;
   s,n,i,z,k:integer;
procedure swap(var a,b:integer);
var
   c:integer;
begin
   c:=a;
   a:=b;
   b:=c;
end;
procedure rec(k:integer);
var
   a1,b1:integer;
begin
   if (b[k]<>-1) then exit;
   rec(k+k);
   rec(k+k+1);
   a1:=b[k+k]+a[k+k];
   b1:=b[k+k+1]+a[k+k+1];
   if (a1>b1) then swap(a1,b1);
   s:=s+b1-a1;
   b[k]:=b1;
end;
begin
   for i:=1 to 4096 do b[i]:=-1;
   for i:=1 to 4096 do a[i]:=0;
   read(n);
   for i:=(1 shl n) to 4096 do b[i]:=0;
   for i:=2 to (1 shl (n+1) - 1) do read(a[i]);
   s:=0;
   rec(1);
   writeln(s);
   readln;
   readln;
end.