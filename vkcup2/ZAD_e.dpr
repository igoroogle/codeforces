program ZAD_e;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
    n,  m, i, j, zz:integer;
    a: array [1..100100] of int64;
    t, s: string;
begin
    readln(n, m);
    readln(t);
    s := '';
    while length(s) < n do s := s + '.';
    for i := 1 to m do
    begin
        read(a[i]);
    end;
    for i := m downto 1 do
    begin
        zz := 0;
        for j := a[i] to a[i]+length(t)-1 do
        begin
            if s[j] <> '.' then break;
            inc(zz);
            s[j] := t[zz];
        end;
    end;
    writeln(s);
end.
