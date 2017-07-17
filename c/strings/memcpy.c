#include <stdio.h>;
#include <string.h>;
#include <inttypes.h>;
 
void mymemcpy1(void *, const void *, size_t );
void mymemcpy2(void *, const void *, size_t );
void mymemcpy3(void *, const void *, size_t );
void mymemcpy4(void *, const void *, size_t );
 
int main(int argc, char **argv) {
 char source[] = &amp;quot;0123456789abdcdefghi&amp;quot;;  // 21 bytes (20 letters + '\0')
    char dest[100];
 
    // void * memcpy ( void * destination, const void * source, size_t num );
    memcpy(dest, source, strlen(source) + 1);
    printf(&amp;quot;Source: %s. Destination: %s\n&amp;quot;, source, dest);
 
    strcpy(source, &amp;quot;0123456789abdcdefghi&amp;quot;);
    mymemcpy1(dest, source, strlen(source) + 1);
    printf(&amp;quot;Source: %s. Destination: %s\n&amp;quot;, source, dest);
 
    strcpy(source, &amp;quot;0123456789abdcdefghi&amp;quot;);
    mymemcpy2(dest, source, strlen(source) + 1);
    printf(&amp;quot;Source: %s. Destination: %s\n&amp;quot;, source, dest);
 
    strcpy(source, &amp;quot;0123456789abdcdefghi&amp;quot;);
    mymemcpy3(dest, source, strlen(source) + 1);
    printf(&amp;quot;Source: %s. Destination: %s\n&amp;quot;, source, dest);
 
    strcpy(source, &amp;quot;0123456789abdcdefghi&amp;quot;);
    mymemcpy4(dest, source, strlen(source) + 1);
    printf(&amp;quot;Source: %s. Destination: %s\n&amp;quot;, source, dest);
    return 0;
}
 
// simple implementation
void mymemcpy1(void *dest, const void *source, size_t num) {
    int i = 0;
    // casting pointers
    char *dest8 = (char *)dest;
    char *source8 = (char *)source;
    printf(&amp;quot;Copying memory %d byte(s) at a time\n&amp;quot;, sizeof(char));
    for (i = 0; i &amp;lt; num; i++) {
        dest8[i] = source8[i];
    }
}
// it checks that destination array does not overwrite
// source memory
void mymemcpy2(void *dest, const void *source, size_t num) {
    int i = 0;
    // casting pointers
    char *dest8 = (char *)dest;
    char *source8 = (char *)source;
    printf(&amp;quot;Copying memory %d byte(s) at a time\n&amp;quot;, sizeof(char));
    for (i = 0; i &amp;lt; num; i++) {
        // make sure destination doesnt overwrite source
        if (&amp;amp;dest8[i] == source8) {
            printf(&amp;quot;destination array address overwrites source address\n&amp;quot;);
            return;
        }
        dest8[i] = source8[i];
    }
}
 
// copies 1 word at a time (8 bytes at a time)
void mymemcpy3(void *dest, const void *source, size_t num) {
    int i = 0;
    // casting pointers
    long *dest32 = (long *)dest;
    long *source32 = (long *)source;
    char *dest8 = (char *)dest;
    char *source8 = (char *)source;
 
    printf(&amp;quot;Copying memory %d bytes at a time\n&amp;quot;, sizeof(long));
    for (i = 0; i &amp;lt; num/sizeof(long); i++) {
        if (&amp;amp;dest32[i] == source32) {
            printf(&amp;quot;destination array address overwrites source address\n&amp;quot;);
            return;
        }
        dest32[i] = source32[i];
    }
    // copy the last bytes
    i*=sizeof(long);
    for ( ; i &amp;lt; num; i++) {
        dest8[i] = source8[i];
    }
}
 
/* memory addres is n-byte aligned when address is multiple of n bytes
   b-bit aligned is equivalent to b/8-byte aligned
   padding = n - (offset &amp;amp; ( -1)) = -offset &amp;amp; (n-1)
   aligned offset = (offset + n-1) &amp;amp; ~(n-1)
 
   Copies 8 bytes at a time with destination align to 64-byte boundary
*/
void mymemcpy4(void * dest, const void * source, size_t size) {
 
#define NBYTE 8 // n-byte boundary
 
    int i = 0;
    int j = 0;
 
    // short and long pointers for copying 1 and 8 (sizeof(long))
    //  bytes at a time
    long * destlong = (long *)dest;
    long * sourcelong = (long *)source;
    char * destshort = (char *)dest;
    char * sourceshort = (char *)dest;
 
 
    // copy first bytes until destination hits 64-byte boundary
    while((((uintptr_t)&amp;amp;destshort[i] &amp;amp; (uintptr_t)(NBYTE-1)) != 0) &amp;amp;&amp;amp; \
          (&amp;amp;destshort[i] != source) &amp;amp;&amp;amp; (i &amp;lt; size)) {
        destshort[i] = sourceshort[i];
        i++;
    }
    printf(&amp;quot;%s: copied %d bytes up to %d-byte alignment\n&amp;quot;,
           __func__, i, NBYTE);
 
 
    // now copy 8 (sizeof(long)) bytes at a time with dest aligned
    // align destination pointer
    destlong = ((uintptr_t)destlong + (NBYTE-1)) &amp;amp; ~(uintptr_t)(NBYTE-1);
     // continue copying where left off (we should align source as well...)
    sourcelong = (long *)sourceshort;
    // j+1 * 8 - 1 to avoid copying beyond last element in last iteration
    while ((j+1)*sizeof(long) - 1 + i &amp;lt; size &amp;amp;&amp;amp;\
            &amp;amp;destlong[j] &amp;lt; (long *)source) {
        destlong[j] = sourcelong[j];
        j++;
    }
    printf(&amp;quot;%s: copied %d bytes %d bytes at a time\n&amp;quot;, __func__,
           j*sizeof(long), sizeof(long));
 
 
    // finally copy last bytes
    i = i + j*sizeof(long);
    int prev_i = i;
    while(i &amp;lt; size &amp;amp;&amp;amp; &amp;amp;destshort[i] &amp;lt; (char *)source) {
        destshort[i] = sourceshort[i];
        i++;
    }
    printf(&amp;quot;%s: copied last %d bytes one at a time\n&amp;quot;,
            __func__, i-prev_i);
 
}
 
/* simpler implementation of mymemcpy4 */
void mymemcpy4b(const void * dest, void * src, size_t size) {
 
    char * dest1 = (char *)dest;
    char * src1 = (char *)src;
    int n = 0;
#define NBYTE 64
    // copy up to nbyte alignment
    while ((((uintptr_t)dest1 & ~(NBYTE-1) != 0x00) && (n < size) {
        *dest1++ = *src1++;
        n++;
    }
    printf("copied %d bytes at a time up to %d bytes\n", sizeof(char), n);
 
    // copy up to end minus last sizeof(long) bytes
    long * dest2 = (long *)dest1;
    long * src2 = (long *)src1;
    while (n &lt; size - sizeof(long)) {
        *dest2++ = *src2++;
        n+=sizeof(long);
    }
    printf("copied %d bytes at a time up to %d bytes\n", sizeof(long), n);
 
    // copy last bytes
    src1 = (char *)src2;
    dest1 = (char *)dest2;
    while (n &lt; size) {
        *dest1++ = *src1++;
        n++;
    }
    printf("copied up to %d bytes\n", n);
}
