program ZAD_D_2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   i,n,m,x,y:integer;
   s:int64;
   a:array [1..100010] of integer;
begin
   readln(n);
   s:=0;
   for i:=1 to n do
      begin
         read(a[i]);
         s:=s+a[i];
      end;
   readln(m);
   if (s mod a[n]=0) and (s div a[n] = n) then
      begin
         writeln(0);
         readln;
         halt;
      end;
   for i:=1 to m do
      begin
         read(x,y);
         s:=s-a[x];
         a[x]:=y;
         s:=s+y;
         if (s mod y=0) and (s div y = n) then
            begin
               writeln(i);
               readln;
               halt;
            end;
      end;
   readln;
   writeln(-1);
   readln;
   halt;
end.
