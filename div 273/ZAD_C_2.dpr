program ZAD_C_2;

{$APPTYPE CONSOLE}

uses
  SysUtils,Math;
var
   r,g,b,r1,gg,bb,maxt,m1,m2,q,n,m:int64;
begin
    readln(r,g,b);
    r1:=r;
    gg:=g;
    bb:=b;
    maxt:=min(min(r,g),b);
    r1:=r1-maxt;
    bb:=bb-maxt;
    gg:=gg-maxt;
    if (gg<>0) then
       begin
          n:=gg;
          if (r1<>0) then m:=r1
          else m:=bb;
       end
    else
       begin
          n:=r1;
          m:=bb;
    end;
    q:=n-(m div 2);
    m1:=min(m div 2,n);
    if (m mod 2<>0) and (q>=2)  then inc(m1);
    q:=m-(n div 2);
    m2:=min(n div 2,m);
    if (n mod 2<>0) and (q>=2) then inc(m2);
    maxt := maxt + max(m1, m2);
    writeln(maxt);
end.
