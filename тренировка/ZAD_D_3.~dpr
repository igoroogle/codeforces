program ZAD_D_3;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   n,m,i,x,y:integer;
   s:int64;
   a:array [1..100010] of integer;
begin
   readln(n);
   read(a[1]);
   s:=0;
   for i:=2 to n do
      begin
         read(a[i]);
         s:=s+abs(a[i]-a[i-1]);
      end;
  readln(m);
  if (s=0) then
     begin
        writeln(0);
        readln;
        halt;
     end;
  for i:=1 to m do
     begin
        readln(x,y);
        if (x>1) then
           begin
              s:=s-abs(a[x]-a[x-1]);
              s:=s+abs(y-a[x-1]);
           end;
        if (x<n) then
           begin
              s:=s-abs(a[x+1]-a[x]);
              s:=s+abs(a[x+1]-y);
           end;
        a[x]:=y;
        if (s=0) then
           begin
              writeln(i);
              readln;
              halt;
           end;
     end;
  writeln(-1);
  readln;
end.
