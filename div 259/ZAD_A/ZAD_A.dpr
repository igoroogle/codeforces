program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a:array [1..110,1..110] of char;
   i,j,n,s,k:integer;
   pr:boolean;
begin
   readln(n);
   for i:=1 to n do
      for j:=1 to n do a[i,j]:='*';
   s:=1;
   pr:=false;
   k:=(n+1) div 2;
   for i:=1 to n do
      begin
         for j:=k to k+s-1 do a[i,j]:='D';
         for j:=k-s+1 to k do a[i,j]:='D';
         if (n=s*2-1) then pr:=true;
         if (pr) then dec(s)
         else inc(s);
      end;
   for i:=1 to n do
      begin
         for j:=1 to n do write(a[i,j]);
         writeln;
      end;
   readln;
end.
