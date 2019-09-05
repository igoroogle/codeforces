program ZAD_B;

{$APPTYPE CONSOLE}
{$M 66666666,66666666}

uses
  SysUtils,Math;
const
   dl = 20000;
   inf = maxint;
var
   a:array [0..dl] of integer;
   i,n,m:integer;
function dfs(x:integer):integer;
var
   a1,b1:integer;
begin
   if (x>dl) or (x<0) then
      begin
         dfs:=inf;
         exit
      end;
   if (a[x]<>-1) then
      begin
         dfs:=a[x];
         exit
      end;
   a[x]:=inf;
   if (not (odd(x))) then a1:=dfs(x div 2)
   else a1:=inf;
   b1:=dfs(x+1);
   a[x]:=min(a1,b1);
   if (a[x]<inf) then inc(a[x]);
   dfs:=a[x];
end;
begin
   readln(n,m);
   for i:=0 to dl do a[i]:=-1;
   a[n]:=0;
   writeln(dfs(m));
   readln;
end.
