#include <stdio.h>


void add_header (const char* name);
void add_footer (void);
void add_backgrounds (const char* background, const char* current, const char* selected);
void add_color (const char* col, const char* name);


int main ( int argc, char** argv )
{
    add_header("jd-light-paper");
    add_backgrounds("#f0f0e8","#f8f8f0","#babdb6");

    add_color("#1A2528","c_nearly_black=#1A2528");
    add_color("#f0f0e8","c_paper_white=#f0f0e8");
    add_color("#f8f8f0","c_nearly_white=#f8f8f0");
    add_color("#a40000","c_red=#a40000");
    add_color("#ef2929","c_bright_red=#ef2929");
    add_color("#555753","c_dark_grey=#555753");
    add_color("#babdb6","c_grey=#babdb6");
    add_color("#d3d7cf","c_bright_grey=#d3d7cf");
    add_color("#4e9a06","c_green=#4e9a06");
    add_color("#8ae234","c_bright_green=#8ae234");
    add_color("#204a87","c_blue=#204a87");
    add_color("#7290bc","c_bright_blue=#7290bc");
    add_color("#75507b","c_purple=#75507b");
    add_color("#2e8a8a","c_cyan=#2e8a8a");
    add_color("#68acac","c_bright_cyan=#68acac");
    add_color("#edd400","c_yellow=#edd400");

    add_footer();
}


static const char svg_header[] = {
"<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n" \
"<svg\n" \
"   xmlns:dc=\"http://purl.org/dc/elements/1.1/\"\n" \
"   xmlns:cc=\"http://creativecommons.org/ns#\"\n" \
"   xmlns:rdf=\"http://www.w3.org/1999/02/22-rdf-syntax-ns#\"\n" \
"   xmlns:svg=\"http://www.w3.org/2000/svg\"\n" \
"   xmlns=\"http://www.w3.org/2000/svg\"\n" \
"   xmlns:sodipodi=\"http://sodipodi.sourceforge.net/DTD/sodipodi-0.dtd\"\n" \
"   xmlns:inkscape=\"http://www.inkscape.org/namespaces/inkscape\"\n" \
"   width=\"210mm\"\n" \
"   height=\"297mm\"\n" \
"   viewBox=\"0 0 744.09448819 1052.3622047\"\n" \
"   id=\"svg2\"\n" \
"   version=\"1.1\"\n" \
"   inkscape:version=\"0.91 r13725\"\n" \
"   sodipodi:docname=\"%s.svg\">\n" \
"  <defs\n" \
"     id=\"defs4\" />\n" \
"  <sodipodi:namedview\n" \
"     id=\"base\"\n" \
"     pagecolor=\"#ffffff\"\n" \
"     bordercolor=\"#666666\"\n" \
"     borderopacity=\"1.0\"\n" \
"     inkscape:pageopacity=\"0.0\"\n" \
"     inkscape:pageshadow=\"2\"\n" \
"     inkscape:zoom=\"0.71268238\"\n" \
"     inkscape:cx=\"-170.97165\"\n" \
"     inkscape:cy=\"523.3748\"\n" \
"     inkscape:document-units=\"px\"\n" \
"     inkscape:current-layer=\"layer1\"\n" \
"     showgrid=\"true\"\n" \
"     inkscape:window-width=\"1680\"\n" \
"     inkscape:window-height=\"984\"\n" \
"     inkscape:window-x=\"0\"\n" \
"     inkscape:window-y=\"27\"\n" \
"     inkscape:window-maximized=\"1\">\n" \
"    <inkscape:grid\n" \
"       type=\"xygrid\"\n" \
"       id=\"grid3338\" />\n" \
"  </sodipodi:namedview>\n" \
"  <metadata\n" \
"     id=\"metadata7\">\n" \
"    <rdf:RDF>\n" \
"      <cc:Work\n" \
"         rdf:about=\"\">\n" \
"        <dc:format>image/svg+xml</dc:format>\n" \
"        <dc:type\n" \
"           rdf:resource=\"http://purl.org/dc/dcmitype/StillImage\" />\n" \
"        <dc:title />\n" \
"      </cc:Work>\n" \
"    </rdf:RDF>\n" \
"  </metadata>\n" \
"  <g\n" \
"     inkscape:label=\"Ebene 1\"\n" \
"     inkscape:groupmode=\"layer\"\n" \
"     id=\"layer1\">\n"
};

static const char svg_footer[] = {
"  </g>\n" \
"</svg>\n"
};


static const char fmt_backgrounds[] = {
"    <rect\n" \
"       style=\"fill:%s;fill-rule:evenodd;stroke:#000000;stroke-width:1.09861362px;stroke-linecap:butt;stroke-linejoin:miter;stroke-opacity:1;fill-opacity:1\"\n" \
"       id=\"rect-%d\"  width=\"400\" height=\"850\" x=\"0\" y=\"10\"\n" \
"       inkscape:label=\"background\" />\n" \
"    <rect\n" \
"       style=\"fill:%s;fill-opacity:1\" id=\"rect-%d\" width=\"40\" height=\"870\" x=\"20\" y=\"0\"\n" \
"       inkscape:label=\"currline\" />\n" \
"    <rect\n" \
"       style=\"fill:%s;fill-opacity:1\" id=\"rect-%d\" width=\"40\" height=\"870\" x=\"90\" y=\"0\"\n" \
"       inkscape:label=\"highlight\" />\n"
};

static const char fmt_color_sample[] = {
"    <rect\n" \
"       style=\"fill:%s;fill-opacity:1\" id=\"rect-%d\" width=\"70\" height=\"20\" x=\"40\" y=\"%d\"\n" \
"       inkscape:label=\"%s\" />\n"
};

static const char fmt_font_sample[] = {
"    <text\n" \
"       xml:space=\"preserve\" style=\"fill:%s;fill-opacity:1;font-style:normal;font-weight:normal;font-size:18px;line-height:125%%;font-family:Sans;letter-spacing:0px;word-spacing:0px;stroke:none;stroke-width:1px;stroke-linecap:butt;stroke-linejoin:miter;stroke-opacity:1;\"\n" \
"       x=\"115\" y=\"%d\" id=\"text-%d\" sodipodi:linespacing=\"125%%\">\n" \
"       <tspan sodipodi:role=\"line\" id=\"tspan-%d\" x=\"115\" y=\"%d\">%s</tspan></text>\n"
};


static int rect_id = 1000;
static int text_id = 2000;
static int pos_y = 25;


void add_backgrounds (const char* background, const char* current, const char* selected)
{
    printf(fmt_backgrounds,background,rect_id++,current,rect_id++,selected,rect_id++);
}

void add_color (const char* col, const char* name)
{
    printf(fmt_color_sample,col,rect_id++,pos_y,name);
    printf(fmt_font_sample,col,pos_y+15,text_id++,text_id++,pos_y+15,name);
    pos_y += 30;
}

void add_header (const char* name)
{
    printf(svg_header,name);
}

void add_footer (void)
{
    printf(svg_footer);
}
