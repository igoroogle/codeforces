program ZAD_G;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   n,m,i:integer;
   a:array [1..1010] of int64;
   s:int64;
begin
   reset(input,'input.txt');
   assign(output,'output.txt');
   read(n,m);
   s:=0;
   for i:=1 to n do
      begin
         read(a[i]);
         s:=(s+a[i]) mod m;
      end;
   readln;
   if (s<>0) then
      begin
         writeln('NO');
         readln;
         halt;
      end;
   writeln('YES');
   s:=0;
   for i:=1 to n-1 do
      begin
         write(s,' ');
         s:=(s+a[i]) mod m;
      end;
   writeln(s);
   readln;
end.
