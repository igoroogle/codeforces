program ZAD_E_2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
    n, answ: integer;
    s, ssss: string;
procedure rec(i, j, k, k1: integer);
begin
    if ((i > n) and (i <= j)) or ((j > n) and (j <= i)) then
    begin
        inc(answ);
        exit;
    end;
    if s[i] <> ssss[j] then
    begin
        if k = 0 then
        begin
            rec(i, j+1, 1, k1);
            rec(i+1, j, 1, k1);
        end;
        if k1 = 0 then
        begin
            rec(i+1, j, k, 1);
            rec(i, j+1, k, 1);
        end;
        exit;
    end;
    rec(i+1, j+1, k, k1);
end;
begin
    readln(n);
    readln(s);
    readln(ssss);
    rec(1, 1, 0, 0);
    writeln(answ div 2);
end.
