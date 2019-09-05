program ZAD_B_2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a:array [1..100010] of integer;
   i,n,min:integer;
begin
   readln(n);
   min:=1;
   read(a[1]);
   for i:=2 to n do read(a[i]);
   readln;
   i:=2;
   while (i<=n) and (a[i]>=a[i-1]) do inc(i);
   if (i<=n) then min:=i
   else
      begin
         writeln(0);
         readln;
         halt;
      end;
   if (a[n]>a[1]) or (a[min]>a[1]) then
      begin
         writeln(-1);
         readln;
         halt;
      end;
   i:=min+1;
   while (i<=n) and (a[i]>=a[i-1]) do inc(i);
   if (i=n+1) then writeln(n-min+1)
   else writeln(-1);
   readln;
end.
