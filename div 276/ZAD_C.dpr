program ZAD_C;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   kol,step1,step2,step3,x,l,r,num,kol1:int64;
   n,i:integer;
begin
  readln(n);
  for i := 1 to n do begin
    readln(l,r);
    kol := 0;
    step1 := 1;
    x := 0;
    while(trunc(1.0 * step1 * 2) <= l) do
      step1 := trunc(2.0 * step1);
    step2 := 1;
    while(trunc(1.0 * step2 * 2) <= r) do
      step2 := trunc(1.0 * step2 * 2);

    while(step1 <= step2) do begin
      num := step1;
      kol1 := 1;
      step3 := 1;
      while(step3 < step1) do begin
        if(num + step3 <= r) then begin
          inc(num, step3);
          inc(kol1);
        end;
        step3 := trunc(1.0 * 2 * step3);
      end;
      if((kol1 > kol) or ((kol1 = kol) and (num < x))) and (num <= r) and (num >= l) then begin
        kol := kol1;
        x := num;
      end;
      step1 := trunc(1.0 * 2 * step1);
    end;
    writeln(x);
  end;
  readln;
end.
