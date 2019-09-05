program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a:array [1..110,1..110] of char;
   n,i,j,s:integer;
begin
   readln(n);
   for i := 1 to n do begin
    for j := 1 to n - 1 do
      read(a[i, j]);
    readln(a[i, n]);
  end;
   for i:=1 to n do
      for j:=1 to n do
         begin
            s:=0;
            if (i-1>=1) and (a[i-1,j]='o') then inc(s);
            if (i+1<=n) and (a[i+1,j]='o') then inc(s);
            if (j-1>=1) and (a[i,j-1]='o') then inc(s);
            if (j+1<=n) and (a[i,j+1]='o') then inc(s);
            if (odd(s)) then
               begin
                  writeln('NO');
                  readln;
                  halt;
               end;
         end;
   writeln('YES');
   readln;
end.
