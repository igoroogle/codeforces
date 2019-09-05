program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;
const
   mx = 1000000000000;
   dl = 2000010;
var
   sum:array [0..dl] of int64;
   a,b,n,l,t,m,l1,r1,m1,x,len:int64;
   i:integer;
begin
   readln(a,b,n);
   sum[0]:=0;
   len:=0;
   for i:=1 to dl do
      begin
         x:=a + trunc(1.0 * (i-1) * b);
         sum[i]:=sum[i-1]+x;
         if (x>mx) then
            begin
               len:=i;
               break;
            end;
      end;
   if (len=0) then len:=dl;
   for i:=1 to n do
      begin
         readln(l,t,m);
         l1:=l;
         r1:=len;
         if (l>len) or (m>then l1:=maxint;
         while (l1<r1) do
            begin
               m1:=(l1+r1) div 2;
               if (trunc(1.0*m*t)>=sum[m1]-sum[l-1]) then l1:=m1+1
               else r1:=m1;
            end;
         if (l1=maxint) then l1:=-1
         else dec(l1);
         writeln(l1);
         //writeln(l1,' ',trunc(1.0*m*t),' ',sum[l+3]-sum[l-1],' ',l+3);
      end;
   readln;
end.
