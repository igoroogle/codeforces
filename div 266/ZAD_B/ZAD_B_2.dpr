program ZAD_B_2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n,x,q,a,b,nn,x1,y1:int64;

begin
    readln(n, a, b);
    x1:=0;
    y1:=0;
    nn := 100000000000;
    if (a * b < n * 6) then
    begin
    
        while (trunc(1.0 * a * 1) < trunc(1.0 * 6 * n)) do
        begin
            q := (trunc(1.0 * 6 * n)) div a;
            if ((trunc(1.0 * 6 * n)) mod a <> 0) then
                inc(q);
            if (a * q >= trunc(1.0 * 6 * n)) and (trunc(1.0 * a * q) < nn) then 
            begin
                nn := trunc(1.0 * a * q);
                x1 := a;
                y1 := q;
            end;
            inc(a);    
        end;
       writeln(nn);
    writeln(x1, ' ', y1);
    end
    else
    begin
        x := trunc(1.0 * a * b);
        writeln(x);
        writeln(a, ' ',b);
    end;   

    readln;
    readln;
end.
 