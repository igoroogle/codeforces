program Project;

{$APPTYPE CONSOLE}

uses
  SysUtils, math;

var
   d, dp, ww:array[0..100010] of int64;
   i, j, u, n, m, t, k, x, y :integer;
   q :int64;


begin
    readln(t, k);

    d[0] := 1;
    if (k > 1) then
        d[1] := 1
    else
        d[1] := 2;
    for i := 2 to 100000 do
    begin
        if (i - k >= 0) then
            d[i] := (d[i - 1] + d[i - k]) mod 1000000007
        else
            d[i] := d[i - 1] mod 1000000007;
    end;

    dp[0] := 0;
    dp[1] := d[1];
    for i := 2 to 100000 do
    begin
        dp[i] := (dp[i - 1] + d[i]) mod 1000000007;
    end;


    q := 0;
    for u := 1 to t do
    begin
        read(x, y);
        inc(q);
        ww[q] := dp[y] - dp[x - 1];
    end;

    for i := 1 to q do
        writeln(ww[i]);

    readln;
    readln;
end.
