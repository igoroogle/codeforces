program ZAD_D;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a:array [1..2010,1..2010] of integer;
   b:array [1..2010] of boolean;
   i,j,n,gor,dor:integer;
procedure dfs(v:integer);
var
   i:integer;
begin
   b[v]:=false;
   for i:=1 to n do
   if (a[v,i]=1) and (b[i]) then dfs(i);
end;
begin
   readln(n);
   for i:=1 to n do
      for j:=1 to n do read(a[i,j]);
   readln;
   for i:=1 to n do
      begin
         if (a[i,i]<>0) then
            begin
               writeln('NO');
               readln;
               halt;
            end;
      end;
   for i:=1 to n do
      for j:=1 to n do
         begin
            if (a[i,j]<>a[j,i]) then
            begin
               writeln('NO');
               readln;
               halt;
            end;
         end;
    gor:=0;
    for i:=1 to n do
       if (b[i]) then
          begin
             inc(gor);
             dfs(i);
          end;
    dor:=0;
    for i:=1 to n do
    for j:=1 to n do
       if (a[i,j]=1) then
          begin
             inc(dor);
             a[i,j]:=0;
             a[j,i]:=0;
          end;
   if (dor+1=n) and (gor=1) then writeln('YES')
   else writeln('NO');
   readln;
end.
