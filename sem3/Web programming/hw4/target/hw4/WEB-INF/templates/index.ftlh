<#-- @ftlvariable name="post.text" type="java.lang.String" -->
<#import "./common.ftlh" as c>
<link rel="stylesheet" href="/css/posts.css"
<@c.page>
    <@c.listPosts 1 ; id, user_id, title, text, daysAgo>
        <article>
            <div class="title">${title}</div>
            <#assign user=c.findBy(users, "id", user_id)/>
            <div class="information">Published by ${user.name}</div>
            <div class="body">
                <p>
                    ${text}
                </p>
            </div>
            <div class="footer">
                <div class="left">
                    <img src="img/voteup.png" title="Vote Up" alt="Vote Up"/>
                    <span class="positive-score">+173</span>
                    <img src="img/votedown.png" title="Vote Down" alt="Vote Down"/>
                </div>
                <div class="right">
                    <img src="img/date_16x16.png" title="Publish Time" alt="Publish Time"/>
                    ${daysAgo} days ago
                    <img src="img/comments_16x16.png" title="Comments" alt="Comments"/>
                    <a href="#">68</a>
                </div>
            </div>
        </article>
    </@c.listPosts>
</@c.page>
