program ZAD_C;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
   a,b,sum:array [0..1000010] of int64;
   n,i,j,x:integer;
   s:int64;
begin
   for i:=1 to 1000010 do b[i]:=0;
   readln(n);
   for i:=1 to n do
      begin
         read(x);
         inc(b[x]);
      end;
   n:=0;
   for i:=1 to 1000010 do
      for j:=1 to b[i] do
         begin
            inc(n);
            a[n]:=i;
         end;
   sum[0]:=0;
   for i:=1 to n do sum[i]:=sum[i-1]+a[i];
   s:=sum[n];
   for i:=0 to n-2 do s:=s-sum[i]+sum[n];
   writeln(s);
   readln;
end.
 