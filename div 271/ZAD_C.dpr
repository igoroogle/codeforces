program ZAD_C;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   d,sum:array [0..100010] of int64;
   i,t,k,a1,b1:integer;
begin
   readln(t,k);
   if (k=1) then d[1]:=2
   else d[1]:=1;
   d[0]:=1;
   sum[1]:=d[1];
   for i:=2 to 100010 do
      begin
         d[i]:=d[i-1];
         if (i-k>=0) then d[i]:=(d[i-k]+d[i]) mod 1000000007;
         sum[i]:=(sum[i-1]+d[i]) mod 1000000007;
      end;
   for i:=1 to t do
      begin
         readln(a1,b1);
         writeln((sum[b1]+1000000007-sum[a1-1]) mod 1000000007);
      end;
   readln;
end.
