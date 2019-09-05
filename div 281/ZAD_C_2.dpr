program ZAD_C_2;
 
{$APPTYPE CONSOLE}
 
uses
  SysUtils,Math;
var
   a,b:array[1..200010] of int64;
   i,n,m:integer;
   x,y,s,mint,maxt:int64;
   mm, ll, rr, l, r :extended;

function prov(d :extended):int64;
var
   i :integer;
   xx, yy :int64;
begin
    xx := 0;
    yy := 0;
    for i := 1 to n do
        if (a[i] < trunc(d)) then
             inc(xx, 2)
        else
             inc(xx, 3);
     for i := 1 to m do
        if (b[i] < trunc(d)) then
             inc(yy, 2)
        else
             inc(yy, 3);
    prov := xx - yy;
    if (xx - yy > s) then
    begin
         s := xx - yy;
         x := xx;
         y := yy;
    end;
end;

begin
    x := -1000000000000000000;
    y := 0;
    s := x;
    readln(n);
    maxt:=-1000000000000000000;
    mint:=1000000000000000000;
    for i := 1 to n do
    begin
        read(a[i]);
        mint := min(a[i], mint);
        maxt := max(a[i], maxt);
    end;
    readln(m);
    for i := 1 to m do
    begin
        read(b[i]);
        mint := min(b[i], mint);
        maxt:= max(b[i], maxt);
    end;

    l := mint - 1;
    r := maxt + 1;
    for i := 1 to 80 do
    begin
        mm := (r + l) / 2;
        ll := (l + mm) / 2;
        rr := (r + mm) / 2;
        if (prov(ll) > prov(rr)) then
              r := rr
        else
              l := ll;
    end;
    writeln(x,':',y);
    readln;
    readln;
end.