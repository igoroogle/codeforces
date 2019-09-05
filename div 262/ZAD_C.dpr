program ZAD_C;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
   a,dp:array [1..200012] of int64;
   l,r,n,m,w,x:int64;
   i:integer;
function prov(p:integer):boolean;
var
   i,k,mt:integer;
begin
   prov:=true;
   mt:=m;
   for i:=1 to n do dp[i]:=0;
   for i:=1 to n do
      begin
         if (a[i]+dp[i]<p) then
            begin
               k:=p-(a[i]+dp[i]);
               if (k<=mt) then
                  begin
                     mt:=mt-k;
                     dp[i]:=dp[i]+k;
                     dp[i+w]:=dp[i+w]-k;
                  end
               else
                  begin
                     prov:=false;
                     exit;
                  end;
            end;
         dp[i+1]:=dp[i+1]+dp[i];
      end;
end;
begin
   readln(n,m,w);
   for i:=1 to n do read(a[i]);
   readln;
   l:=1;
   r:=2000000001;
   while (l+1<r) do
      begin
         x:=(l+r) div 2;
         if (prov(x)) then l:=x
         else r:=x;
      end;
   writeln(l);
   readln;
end.
