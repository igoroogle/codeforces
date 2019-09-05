program ZAD_B;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a:array [1..100010] of integer;
   i,n,min,st:integer;
begin
   readln(n);
   min:=1;
   read(a[1]);
   for i:=2 to n do
      begin
         read(a[i]);
         if (a[i]<a[min]) then min:=i;
      end;
   readln;
   i:=min;
   st:=a[i];
   if (i=n) then i:=1
   else inc(i);
   while i<>min  do
      begin
      if (a[i]>=st) then st:=a[i]
      else
         begin
            writeln(-1);
            readln;
            halt;
         end;
      if (i=n) then i:=1
      else inc(i);
   end;
   if (min=1) then writeln(0)
   else writeln(n-min+1);
   readln;
end.
