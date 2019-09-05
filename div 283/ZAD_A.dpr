program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a:array [1..110] of integer;
   n,i,j,min,k:integer;
begin
   read(n);
   min:=maxint;
   for i:=1 to n do read(a[i]);
   for i:=2 to n-1 do
      begin
         k:=a[i+1]-a[i-1];
         for j:=2 to n do
            if (j<>i) and (j-1<>i) and (a[j]-a[j-1]>k) then k:=a[j]-a[j-1];
         if (k<min) then min:=k;
      end;
   writeln(min);
   readln;
   readln;
end.
