program ZAD_B;

{$APPTYPE CONSOLE}

uses
  SysUtils,Math;
var
   d:array [1..310,1..310] of integer;
   a:array [1..310] of integer;
   i,j,k,n,dd:integer;
   ch:char;
begin
   read(n);
   for i:=1 to n do read(a[i]);
   readln;
   for i:=1 to n do
      begin
         for j:=1 to n-1 do
            begin
               read(ch);
               if (ch='1') then d[i,j]:=1
               else d[i,j]:=maxint;
               if (i=j) then d[i,j]:=0;
            end;
         readln(ch);
         if (ch='1') then d[i,n]:=1
         else d[i,n]:=maxint;
         if (i=n) then d[i,n]:=0;
      end;
   for k:=1 to n do
      for i:=1 to n do
         for j:=1 to n do
			if (d[i][k] < maxint) and (d[k][j] < maxint) then
          d[i][j]:=min (d[i][j], d[i][k] + d[k][j]);
   for i:=1 to n do
      for j:=i+1 to n do
         if (d[i,j]<>maxint) and (a[j]<a[i]) then
            begin
               dd:=a[i];
               a[i]:=a[j];
               a[j]:=dd;
            end;
   for i:=1 to n-1 do write(a[i],' ');
   writeln(a[n]);
   readln;
end.
