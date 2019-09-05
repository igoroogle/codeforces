program ZAD_D;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a, d:array[1..100000] of integer;
   n, m, i, j, q:integer;
begin
   readln(n);
   read(m);
   for i := 1 to m do
   begin
       read(j);
       inc(d[j]);
   end;
   read(m);
    for i := 1 to m do
   begin
       read(j);
       inc(d[j]);
   end;
   q := 0;
   for i := 1 to n do
       if (d[i] = 0) then
           inc(q);
   if (q = 0) then
   writeln('I become the guy.')
   else
      writeln('Oh, my keyboard!');
   readln;
end.
