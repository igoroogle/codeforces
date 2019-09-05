program ZAD_C;

{$APPTYPE CONSOLE}

uses
  SysUtils;
const
   dl = 100010;
var
   a,b:array [1..dl] of int64;
   i,n,x:integer;
begin
   readln(n);
   for i:=1 to dl do a[i]:=0;
   for i:=1 to n do
      begin
         read(x);
         inc(a[x]);
      end;
   readln;
   b[1]:=a[1];
   if (a[2]*2>b[1]) then b[2]:=a[2]*2
   else b[2]:=b[1];
   for i:=3 to dl do
      begin
         if (b[i-1]>b[i-2]+a[i]*i) then b[i]:=b[i-1]
         else b[i]:=b[i-2]+a[i]*i;
      end;
   writeln(b[dl]);
   readln;
end.
