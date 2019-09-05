program ZAD_C;

{$APPTYPE CONSOLE}

uses
  SysUtils,Math;

var
   s:extended;
   i,m,n:integer;
begin
    readln(m,n);
   s:=0;
   for i:=1 to m do
      begin
         s:=s+(i*(power(i,n)-power(i-1,n))/power(m,n));
      end;
   writeln(s);
   readln;
end.
