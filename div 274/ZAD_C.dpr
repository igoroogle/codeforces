program ZAD_C;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   n:int64;
   m,i,max:integer;
   a:array [1..16] of int64;
procedure rec(s:int64; k,t:integer);
begin
   if (s>=n) then
      begin
         if (s>n) and (max=-1) then max:=0
         else if (s=n) and ((k<max) or (max<1)) then max:=k;
         exit;
      end;
   if (t>m) then exit;
   rec(s+a[t],k+1,t+1);
   rec(s+a[t]*2,k+2,t+1);
   rec(s,k,t+1);
end;
begin
   read(n,m);
   for i:=1 to m do read(a[i]);
   max:=-1;
   rec(0,0,1);
   writeln(max);
   readln;
   readln;
end.
