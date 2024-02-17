<#-- @ftlvariable name="logged_user_id" type="java.lang.String" -->
<#-- @ftlvariable name="user_id" type="java.lang.Long" -->
<#-- @ftlvariable name="handle" type="java.lang.String" -->
<#import "./common.ftlh" as c>

<@c.page>
    <#if handle??>
        <#assign u = c.findBy(users, "handle", handle)!/>
    <#elseif user_id??>
        <#assign u = c.findBy(users, "id", user_id)!/>
    </#if>

    <#if u?has_content && u.id != -1>
        <#assign user_post_count=0/>
        <@c.listPosts 1; id, user_id, title, text, daysAgo>
            <#if user_id == u.id>
                <#assign user_post_count++/>
            </#if>
        </@c.listPosts>
        <div class="userRec">
            <div class="userInfo">
                <#assign classType="${u.color}"/>
                <#if logged_user_id?? && logged_user_id == u.id>
                    <#assign classType="default"/>
                </#if>
                <h2><a href="#" class="${classType}">${u.name}</a></h2>
                <ul>
                    <li>id: ${u.id}</li>
                    <li>handle: ${u.handle}</li>
                    <li>name: ${u.name}</li>
                    <li>Posts: <a href="/post?user_id=${u.id}">${user_post_count}</a></li>
                </ul>
            </div>
            <img src="/img/littleperson.jpg" alt="littleperson">
        </div>
        <#assign lastUser = c.lastItem(users, "id", u.id)/>
        <#assign nextUser = c.nextItem(users, "id", u.id)/>
        <div class="arrows-container">
            <div class="arrows">
                <#if lastUser.id != -1>
                    <p id="leftArrow">
                        <@c.userlinkAltText lastUser "active-arrow">&#8592;</@c.userlinkAltText>
                    </p>
                <#else>
                    <p class="not-active-arrow" id="leftArrow">
                        &#8592;
                    </p>
                </#if>
            </div>
            <div class="arrows">
                <#if nextUser.id != -1>
                    <p id="leftArrow">
                        <@c.userlinkAltText nextUser "active-arrow">&#8594;</@c.userlinkAltText>
                    </p>
                <#else>
                    <p class="not-active-arrow" id="leftArrow">
                        &#8594;
                    </p>
                </#if>
            </div>
        </div>
    <#else>
        No such user
    </#if>
</@c.page>
