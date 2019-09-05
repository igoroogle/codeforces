program ZAD_F;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
   dp:array [-1..1010] of int64;
   n:int64;
   k,i:integer;
   l,r,m:int64;
function rec(z:int64):boolean;
var
   s,t:int64;
   i,j:integer;
   f:boolean;
   begin
      s:=0;
      i:=0;
      t:=z;
      f:=true;
      while t>0 do
         begin
            j:=t mod k;
            s:=s+trunc(1.0*dp[i-1]*j);
            if odd(i) then s:=s+j;
            if (s>=n) then
               begin
                  f:=false;
                  break;
               end;
            t:=t div k;
            inc(i);
         end;
      rec:=f;
   end;
begin
   reset(input,'numbers.in');
   assign(output,'numbers.out');
   readln(n,k);
   dp[1]:=k-1;
   dp[0]:=0;
   dp[-1]:=0;
   for i:=2 to 1010 do
      begin
         dp[i]:=trunc(1.0*dp[i-1]*k);
         if odd(i) then dp[i]:=dp[i]+k-1;
         r:=i+1;
         if (dp[i]>n) then break;
      end;
  l:=0;
  r:=trunc(exp(ln(k)*r));
   while l<r do
      begin
         m:=(r+l) div 2;
         if (rec(m)) then l:=m+1
         else r:=m;
      end;
  writeln(l);
  readln;
end.
