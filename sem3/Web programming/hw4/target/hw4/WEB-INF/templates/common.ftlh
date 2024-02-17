<#-- @ftlvariable name="page_title" type="java.lang.String" -->
<#macro page>
    <!DOCTYPE html>
    <html lang="ru">
    <head>
        <meta charset="UTF-8">
        <title>Codeforces</title>
        <link rel="stylesheet" href="/css/normalize.css">
        <link rel="stylesheet" href="/css/style.css">
        <link rel="icon" href="/favicon.ico">
    </head>
    <body>
    <@header/>
    <div class="middle">
        <@sidebar/>
        <main>
            <#nested/>
        </main>
    </div>
    <@footer/>
    </body>
    </html>
</#macro>

<#macro header>
    <header>
        <a href="#" class="logo"><img alt="Codeforces" title="Codeforces"
                                      src="/img/codeforces-logo-with-telegram.png"></a>
        <div class="languages">
            <a href="#"><img alt="In English" title="In English"
                             src="/img/gb.png"></a>
            <a href="#"><img alt="In Russian" title="In Russian"
                             src="/img/ru.png"></a>
        </div>
        <div class="enter-or-register-box">
            <#if user??>
                <@userlink user/>
                |
                <a href="/logout">Logout</a>
            <#else>
                <a href="/enter">Enter</a>
                |
                <a href="/register">Register</a>
            </#if>
        </div>
        <nav>
            <#assign items=[
            {"href": "/index", "name": "Home"},
            {"href": "/misc/help", "name": "Help"},
            {"href": "/contests", "name": "Contests"},
                {"href": "/users", "name": "Users"}
            ]/>
            <ul>
                <#assign classType="">
                <#list items as item>
                    <#if item.href?ends_with(page_title)>
                        <#assign classType = "menu_item">
                    <#else>
                        <#assign classType = "">
                    </#if>
                    <li>
                        <a href="${item.href}" class=${classType}>${item.name}</a>
                    </li>
                </#list>
            </ul>
        </nav>
    </header>
</#macro>

<#macro sidebar>
    <aside>
        <@listPosts 1; id, user_id, title, text, daysAgo>
            <section>
                <div class="header">${title}</div>
                <div class="body">
                    ${text}
                </div>
                <div class="footer">
                    <a href="/post?post_id=${id}">View all</a>
                </div>
            </section>
        </@listPosts>
    </aside>
</#macro>

<#macro footer>
    <footer>
        2010-2021 &copy; by Mike Mirzayanov
    </footer>
</#macro>

<#macro userlink user>
<#-- @ftlvariable name="user" type="ru.itmo.web.hw4.model.User" -->
    <a href="/user?handle=${user.handle}">${user.name}</a>
</#macro>

<#macro userlinkAltText user classtype>
<#-- @ftlvariable name="user" type="ru.itmo.web.hw4.model.User" -->
    <a href="/user?handle=${user.handle}" class=${classtype}><#nested/></a>
</#macro>

<#macro listPosts short>
    <#list posts?sort_by("daysAgo") as post>
        <#if post?has_content>
            <#assign text = post.text/>
            <#if short == 1>
                <#assign text = post.text?truncate_c(350)/>
            </#if>
            <#nested post.id, post.user_id, post.title, text, post.daysAgo/>
        </#if>
    </#list>
</#macro>

<#function findBy items key value>
    <#list items as item>
        <#if item[key] == value>
            <#return item/>
        </#if>
    </#list>
    <#return items[0]/>
</#function>

<#function lastItem items key value>
    <#assign ans = items[0]>
    <#list items as item>
        <#if item[key] == value>
            <#return ans/>
        </#if>
        <#assign ans = item>
    </#list>
</#function>

<#function nextItem items key value>
    <#assign ans = items[0]>
    <#assign haveAns = 0>
    <#list items as item>
        <#if haveAns == 1>
            <#return item/>
        </#if>
        <#if item[key] == value>
            <#assign haveAns = 1>
        </#if>
    </#list>
    <#return ans>
</#function>

<#--<#function getPost id short>-->
<#--    <#assign ans = findBy(posts, "id", id)/>-->
<#--    <#if short == 1>-->
<#--        <#assign ans[2] = ans.text?truncate_c(350)/>-->
<#--    </#if>-->
<#--    <#return ans>-->
<#--</#function>-->