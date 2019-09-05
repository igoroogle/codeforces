program ZAD_E;

{$APPTYPE CONSOLE}

uses
  SysUtils;
const
   dl = 2000100;
var
   a:array [1..26] of integer;
   b,c:array [1..dl] of int64;
   f1,f2:array [1..dl] of integer;
   fact:array [0..19] of int64;
   kol1,kol2,n,m,k,i,l,r,t,z,fs,ls:integer;
   s,ss:int64;
procedure rec (poz,fct:integer;sum:int64);
begin
   if (poz>m) then
      begin
         inc(kol1);
         b[kol1]:=sum;
         f1[kol1]:=fct;
         exit;
      end;
   rec(poz+1,fct,sum);
   rec(poz+1,fct,sum+a[poz]);
   if (fct<k) and (a[poz]<19) then rec(poz+1,fct+1,sum+fact[a[poz]]);
end;
procedure rec2 (poz,fct:integer;sum:int64);
begin
   if (poz>n) then
      begin
         inc(kol2);
         c[kol2]:=sum;
         f2[kol2]:=fct;
         exit;
      end;
   rec2(poz+1,fct,sum);
   rec2(poz+1,fct,sum+a[poz]);
   if (fct<k) and (a[poz]<19) then rec2(poz+1,fct+1,sum+fact[a[poz]]);
end;
procedure swap(var a,b:int64);
var
   c:int64;
begin
   c:=a;
   a:=b;
   b:=c;
end;
procedure swap2(var a,b:integer);
var
   c:integer;
begin
   c:=a;
   a:=b;
   b:=c;
end;
procedure quicksort(f,l:integer);
var
   i,j,t,y:integer;
   x:int64;
begin
   randomize;
   t:=random(l-f+1)+f;
   x:=b[t];
   y:=f1[t];
   i:=f;
   j:=l;
   repeat
      while (b[i]<x) or ((b[i]=x) and (f1[i]<y)) do inc(i);
      while (b[j]>x) or ((b[j]=x) and (f2[j]>y)) do dec(j);
      if (i<=l) then
         begin
            swap(b[i],b[j]);
            swap2(f1[i],f1[j]);
            inc(i);
            dec(j);
         end;
   until i>j;
   if (i<l) then quicksort(i,l);
   if (f<j) then quicksort(f,j);
end;
function srv(x,y:integer):integer;
begin
   if (b[x]<c[y]) then srv:=-1
   else if (b[x]>c[y]) then srv:=1
   else if (f1[x]<f2[y]) then srv:=-1
   else if (f1[x]>f2[y]) then srv:=1
   else srv:=0;
end;
begin
   fact[0]:=1;
   for i:=1 to 19 do fact[i]:=trunc(1.0*fact[i-1]*i);
   read(n,k,s);
   for i:=1 to n do read(a[i]);
   if (n=1) then
      begin
         kol1:=0;
         if (a[1]=s) then inc(kol1);
         if (a[1]<19) and (fact[a[1]]=s) then inc(kol1);
         writeln(kol1);
         readln;
         readln;
         halt;
      end;
   kol1:=0;
   kol2:=0;
   m:=n div 2;
   rec(1,0,0);
   rec2(m+1,0,0);
   quicksort(1,kol1);
   ss:=0;
   for i:=1 to kol2 do
      begin
         l:=1;
         r:=kol1;
         t:=c[i];
         z:=f2[i];
         c[i]:=s-t;
         f2[i]:=0;
         while (l<r) do
            begin
               m:=(l+r) div 2;
               if (srv(m,i)=-1) then l:=m+1
               else r:=m;
            end;
         f2[i]:=0;
         if (srv(l,i)>-1) and (b[l]=c[i]) and (f1[l]<=k-z) then fs:=l
         else fs:=-1;
         f2[i]:=k-z+1;
         l:=1;
         r:=kol1;
         while (l<r) do
            begin
               m:=(l+r) div 2;
               if (srv(m,i)=-1) then l:=m+1
               else r:=m;
            end;
         f2[i]:=0;
         if (srv(l,i)>-1) and (b[l]=c[i]) and (f1[l]<=k-z) then ls:=l
         else if (l>1) and (srv(l-1,i)>-1) and (b[l-1]=c[i])
         and (f1[l-1]<=k-z) then ls:=l-1
         else ls:=-1;
         f2[i]:=z;
         if (fs<>-1) and (ls<>-1) then ss:=ss+ls-fs+1;
      end;
   writeln(ss);
   for i:=1 to kol1 do write(b[i],' ',f1[i],' ');
   writeln;
   for i:=1 to kol2 do write(c[i],' ',f2[i],' ');
   writeln;
   readln;
   readln;
end.
