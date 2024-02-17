<#-- @ftlvariable name="logged_user_id" type="java.lang.String" -->
<#import "./common.ftlh" as c>

<@c.page>
    <link rel="stylesheet" href="/css/table.css">
    <div class="datatable">
        <div class="caption">Submissions</div>
        <table>
            <thead>
            <tr>
                <th>Id</th>
                <th>Handle</th>
                <th>User</th>
                <th>Status</th>
                <th>Test</th>
            </tr>
            </thead>
            <tbody>
            <#list users as user>
                <#if user.id != -1>
                    <tr>
                        <td>${user.id}</td>
                        <td>${user.handle}</td>
                        <#assign classType="${user.color}"/>
                        <#if logged_user_id?? && logged_user_id == user.id>
                            <#assign classType="default"/>
                        </#if>
                        <td><a href="/user?user_id=${user.id}" class=${classType}>${user.name}</a></td>
                        <td>Accepted</td>
                        <td>391</td>
                    </tr>
                </#if>
            </#list>
            </tbody>
        </table>
    </div>
</@c.page>
